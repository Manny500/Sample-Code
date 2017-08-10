//define all key global variables
var colorMach = 'track', //used later to get color scheme
    ticks = [], //keeps track of # of tracks
    keepTrack = [], //keeps track of the # intances each flowcell has
    seenArray = []; //used to track if a new track is being added

//set the dimentions for the graph
var margin = { top: 50, right: 100, bottom: 100, left: 250 };

//set the dimentions for the svg work space/canvas
var outerWidth = 1150,
    outerHeight = 450;

//calculate the height and width of the graph
var width = outerWidth - margin.left - margin.right,
    height = outerHeight - margin.top - margin.bottom;

/*
 *@param string is the a of the flowcell
 *@return count is the number of times an identical flowcell has been added
 *returns the number of times a a/flowcell has been added
 */
function instances(string){

  var count = 1;

  for(var i = 0; i < keepTrack.length; i++){

    if(string == keepTrack[i]){

      count++;
    }
  }

  keepTrack.push(string); //add to be referenced later

  return count;
}

//set the scale of the graph for x and y axis
//will scale according to browser and data size
var x = d3.time.scale()
    .range([0, width]); //according to time 

var y = d3.scale.linear()
    .range([height, 0]);

//Define time parsing function, used to parce the times
var parsetime = d3.time.format.utc("%Y-%m-%dT%H:%M:%S.%L%L").parse;

//define labels and ticks of the x-axis
var xAxis = d3.svg.axis().scale(x)
    .orient("bottom")
    .tickSize(-height)
    .tickPadding(6)
    .ticks(6);

//define labels and ticks of the y-axis
var yAxis = d3.svg.axis().scale(y)
    .orient("left")
    .tickValues(ticks)
    .tickFormat(function(d,i){
      return seenArray[i];
    })
    .tickPadding(2);

/*
 *@param strMach is the a of the track
 *@return i is the value for the track
 *returns the value for that track so it can be plotted
 */
function seen(strMach){

  var bool = false;

  for(var i = 0; i <= seenArray.length; i++){
    
    if(strMach == seenArray[i]){

      bool = true;
      return i + 1;
    }
  }

  //if not found add to array and give new index
  if(bool == false){

    seenArray.push(strMach); //add to be referenced later

    ticks.push(seenArray.length); //add to name the ticks on y axis

    return seenArray.length;
  }

}

//get the data ***must include headers****
//binds the file inputs to the "data" database
d3.tsv("event_gathering/data/example_input.tsv", function(data){
  data.forEach(function(d){

    //bind the data to d.a- along with its instance number
    d.a = d.a + "-" + instances(d.a);

    //parse the time and bind to d.time
    d.time = parsetime(d.time);

    value = seen(d.track);
    
    d.track = value;
  });

  //get the maximun and minimum values to be plotted
  var xMax = d3.max(data, function(d) { return d.time; }) * 1.05,
      xMin = d3.min(data, function(d) { return d.time; }),
      //xMin = xMin > 0 ? 0 : xMin,
      yMax = d3.max(data, function(d) { return d.track; }) * 1.05;
      //yMin = d3.min(data, function(d) { return d.track; }),
      //yMin = yMin > 0 ? 0 : yMin;

  var xMax1 = d3.max(data, function(d) { return d.time; });

  //set the domain according to the max and min
  x.domain([xMin, xMax]);
  y.domain([.4, yMax]);

  //call the colors palet of 10 colors
  var color = d3.scale.category10();

  //Define the mouseover feature
  //display a, time, and directiory
  var tip = d3.tip()
      .attr("class", "d3-tip")
      .offset([-10, 0])
      .html(function(d) {
        return "name" + ": " + d.a + "<br>" + "time" + ": " + d.time + "<br>" + "Dir" + ": " + d.b;
      });

  //define function that calls zoom
  //y drag and zoom disabled, for more of a timeline feel
  var zoomBeh = d3.behavior.zoom()
      .x(x)
      //.y(y)
      //.scaleExtent([0, 500])
      .on("zoom", zoom);

  // Adds the svg canvas
  var svg = d3.select("#scatter")
    .append("svg")
      .attr("width", outerWidth)
      .attr("height", outerHeight)
    .append("g")
      .attr("transform", "translate(" + margin.left + "," + margin.top + ")")
      .call(zoomBeh);

  //call the mouse over function to enabled
  svg.call(tip);

    //draws the guide lines
  svg.append("rect")
      .attr("width", width)
      .attr("height", height);

  //Aligns the canvas to the specifications
  //$("svg").css({top: 550, left: 60, position:'absolute'});

  // specifies and draws the x-axis
  svg.append("g")
    .attr("class", "x axis")
    .attr("transform", "translate(0," + height + ")")
    .call(xAxis)
    .selectAll("text")  
      .style("text-anchor", "end")
      .attr("dx", "-.8em")
      .attr("dy", ".15em")
      .attr("transform", "rotate(-65)" );

  // Add x axis title
  svg.append("text")
    .attr("transform", "translate(0," + height + ")")
    .attr("x", width)
    .attr("y", margin.bottom - 5)
    .style("text-anchor", "middle")
    .text("Time"); //title

  //specifies and draws y-axis with title
  svg.append("g")
    .classed("y axis", true)
    .call(yAxis)
    .append("text")
      .classed("label", true)
      .attr("transform", "rotate(-90)")
      .attr("y", -margin.left + 25)
      .attr("dy", ".71em")
      .style("text-anchor", "end")
      .text("Tracks"); //title

  //define objects such as dots
  var objects = svg.append("svg")
      .classed("objects", true)
      .attr("width", width)
      .attr("height", height);

  //transforms the lines after zoom or pan
  objects.append("svg:line")
      .classed("axisLine hAxisLine", true)
      .attr("x1", 0)
      .attr("y1", 0)
      .attr("x2", width)
      .attr("y2", 0)
      .attr("transform", "translate(0," + height + ")");

  //draws the guide lines
  objects.append("svg:line")
      .classed("axisLine vAxisLine", true)
      .attr("x1", 0)
      .attr("y1", 0)
      .attr("x2", 0)
      .attr("y2", height);

  /* 
   *@param arg is the a of flowcell
   *@param arg1 is the time
   *@param arg2 is the b
   *will display the flowcell info on screen when clicked
   */
  function displayInfo(arg, arg1, arg2) {

    var div = document.getElementById("textBox");
    div.innerHTML = "<br />" + arg + "<br />" + arg1 + "<br />" + arg2;
  }

  //draw the dots and assigns colors
  objects.selectAll(".dot")
    .data(data)
  .enter().append("circle")
      .classed("dot", true)
      .attr("transform", transform)
      .style("fill", function(d){ return color(d[colorMach]); })
      .on("mouseover", tip.show)
      .on("mouseout", tip.hide)
      .on("click", function(d){ //get info about flowcell
        var arg = "name" + ": " + d.a ;
        var arg1 = "time" + ": " + d.time ;
        var arg2 = "Dir" + ": " + d.b;
        displayInfo(arg,arg1,arg2); //calls funtion on click
      })
      .attr("r", 5);

  //make view display newest events
  change("name", true, "newest");

  //make the button act when clicked upon
  document.getElementById("click").onclick = function(){

  //calls the change/focus method
  change(document.getElementById("id").value, false, "NA");

  };

   //make the button act when clicked upon
  document.getElementById("clickNow").onclick = function(){

  //calls the change/focus method
  change(document.getElementById("id").value, true, "NA");

  };

  /* 
   *@param str is the a of the flowcell
   *will display the flowcell info on screen when clicked
   */
  function change(str, bool, newE) {

    data.forEach(function(d){ 

      var d;

        //find the specified flowcell
        if (d.a == str && bool == false){

          //get a range where the dot is visible
          xMax = d3.time.second.offset(d.time, 1); 
          xMin = d3.time.second.offset(d.time, -1);

        }else if(bool == true && newE != "newest"){

          d = new Date();

          xMin = d3.time.day.offset(d, -1);
          xMax = d3.time.day.offset(d, 1);

        }else if(newE == "newest" ){

          d = xMax1;

          xMin = d3.time.hour.offset(d, -12);
          xMax = d3.time.hour.offset(d, 12);
        }
  });

    zoomBeh.x(x.domain([xMin, xMax])); //zooms to specific range

    //following acts tranform/move the dots according to the view
    var svg = d3.select("#scatter").transition();

    svg.select(".x.axis").duration(750).call(xAxis).select(".label").text("Time"); //name of x-axis

    objects.selectAll(".dot").transition().duration(1000).attr("transform", transform);
  }

  /* 
   *zoom allows the graph to dragged and zoom 
   *Transform both the axisis and the plots
   */
  function zoom() {

    //calls the x and y axis
    svg.select(".x.axis").call(xAxis);
    svg.select(".y.axis").call(yAxis);

    //need to transform labels every zoom or pan
    svg.select(".x.axis").selectAll("text")  
      .style("text-anchor", "end")
      .attr("dx", "-.8em")
      .attr("dy", ".15em")
      .attr("transform", "rotate(-65)" );

    //transform the dots
    svg.selectAll(".dot")
        .attr("transform", transform);
  }

  /* 
   *@return will return the new calculated x and y coordinates
   *will tranform the plots when graph is dragged or zoomed
   *does this with build in translate function
   */
  function transform(d) {
   
    return "translate(" + x(d.time) + "," + y(d.track) + ")";
  }

});//end of database
