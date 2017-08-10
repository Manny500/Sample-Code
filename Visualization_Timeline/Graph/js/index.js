 //global arrays to store parsed data to
var parsedText = [];

//Will parse in the data from a txt or tsv file
function ReadFile(file){

  var txtFile;

  if(window.XMLHttpRequest){
  
    txtFile = new XMLHttpRequest();
  }else{

    txtFile = new ActiveXObject("Microsoft.XMLHTTP");
  }

  txtFile.onreadystatechange = function(){

    if(txtFile.readyState == 4){

      //contains single string
      var AllText = txtFile.responseText;

      //contains an array of the lines in the txt
      var lines = AllText.split("\n");
      
      //in order to return lines call intoArray
      intoArray(lines);
    }
  }

  txtFile.open("GET", file, false);
  txtFile.send();
}

//sets the local array lines equal to the global array parseTxt
function intoArray(lines){

    parsedText = lines;

}

//calls the method
ReadFile("example_input.tsv");
////////////////////////////Time-Based-Pseudo-Threading/////////////////////

//data-an array of items to process
//handler- a function to process individual data item
//callback- an option function called when all processing is complete
function ProcessArray(data, handler, callback){

  var maxtime = 100; //chuck of processing time
  var delay = 20; //delay between processes
  var queue = data.concat(); //clone original array

  setTimeout(function() {

    var endtime = +new Date() + maxtime;

    do{

      handler(queue.shift());

    }while (queue.length > 0 && endtime > +new Date());

    if (queue.length > 0){
    
      setTimeout(arguments.callee, delay);

    }else{

       if (callback) callback();
    }
  }, delay);
}//end of processArray

//process is comple
function Done(){

  console.log("Done");
}

///////////////////////////TEST TIME BASED THREADING/////////////
var keepTrack = [];

function instances(string){

  var count = 1;

  for(var i = 0; i < keepTrack.length; i++){

    if(string == keepTrack[i]){

      count++;
    }
  }

  keepTrack.push(string)

  return count;

}
var prev = 1;
var gindex = 1;
function addNode(singleItem) {

  var str = singleItem.split("\t");

  var num = instances(str[0]);
  var inside = str[0] + "-" + num;

  var num1 = instances(str[1]);
  var inside1 = str[1] + "-" + num1;

  var num2 = instances(str[2]);
  var inside2 = str[2] + "-" + num2;

  var num3 = instances(str[3]);
  var inside3 = str[3] + "-" + num3;

    try {
        nodes.add(
        {
            id: inside,
            label: str[0],
            group: gindex
        });
        nodes.add({
            id: inside1,
            label: str[1],
            group: gindex
        });
        nodes.add({
            id: inside2,
            label: str[2],
            group: gindex
        });
        nodes.add({
            id: inside3,
            label: str[3],
            group: gindex
        }
        );
    }
    catch (err) {
        alert(err);
    }
    addEdge(inside2, inside1);
    addEdge(inside2, inside);
    addEdge(inside2, inside3);
    addEdge(inside2, prev);
    prev = inside2;
    gindex = gindex + 1;
}

var index = 0;
function addEdge(from1, to1) {
  index = index + 1; 
    try {
        edges.add({
            id: index,
            from: from1,
            to: to1
        });
    }
    catch (err) {
        alert(err);
    }
}

// create an array with nodes
  var nodes = new vis.DataSet();

  // create an array with edges
  var edges = new vis.DataSet();

  // create a network
  var container = document.getElementById('mynetwork');

  var data = {
    nodes: nodes,
    edges: edges
  };

  var options = {
   layout: {
      hierarchical: {
          treeSpacing: 20000000,
          nodeSpacing: 200,
          levelSeparation: 200,
          direction: 'LR'

      }
    },
     "physics": {
    "barnesHut": {
      "damping": 1,
      "avoidOverlap": 1
    },
    "minVelocity": 0.75
  }
  };

  ProcessArray(parsedText, addNode, Done);

  var network = new vis.Network(container, data, options);
  
  document.getElementById("clickMe1").onclick = function(){

  network.fit();
};

  //make the button act when clicked upon
document.getElementById("clickMe").onclick = function(){

  network.moveTo({scale: .8 });
  network.focus(document.getElementById("id").value);
  
};