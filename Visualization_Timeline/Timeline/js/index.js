//global arrays to store parsed data to
var parsedText = [];
var mirrorParsedText = [];

//Will parse in the data from a txt or tsv file
function ReadFile(file, bool){

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
			intoArray(lines, bool);
		}
	}

	txtFile.open("GET", file, false);
	txtFile.send();
}

//sets the local array lines equal to the global array parseTxt
function intoArray(lines, bool){

	if( bool == false){

		parsedText = lines;

	}else {

		mirrorParsedText = lines;

	}
}

//calls the method
ReadFile("event_gathering/data/example_input.tsv", false);

//calls read on the second file
ReadFile("event_gathering/data/Example_workflow_output.txt", true);

////////////////////////////Time-Based-Pseudo-Threading/////////////////////

//data-an array of items to process
//handler- a function to process individual data item
//callback- an option function called when all processing is complete
function ProcessArray(data, handler, callback){

	var maxtime = 100; //chuck of processing time
	var delay = 20;	//delay between processes
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

///////////////////////////TEST TIME BASED THREADING/////////////

//process an individual dataitem
function process(dataitem){

	console.log(dataitem);
}

//process is comple
function Done(){

	console.log("Done");
}

//test data

//var data = []

//for (var i = 0; i < 500; i++) data[i] = i

//process all items
//ProcessArray(data, process, Done);

///////////////////////////////////CONFIGURE TIMELINE(S)//////////////////

// DOM element where the Timeline will be attached
var container = document.getElementById('visualization');
var container1 = document.getElementById('visualization');

// Create a DataSet (allows two way data-binding)
var items = new vis.DataSet([
	
]);

var items1 = new vis.DataSet([
	
]);

var arrayLength = parsedText.length;
var arrayLength = mirrorParsedText.length;

//adds all items from file to timeline at once
function addItems(arrayLength, items){

	//loop adds items made from the list to the dataset
	for (var i = 0; i < arrayLength-1; i++){

		//str is an array made of strings separated by tab
		var str = parsedText[i].split("\t");

		items.add([

			{id: i, content: str[2], start: str[0], group: str[1]}

		]);
	}
}

//function addItems call adds items from file to dataset
//addItems(arrayLength, items);
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
//variable to set ids-temporary for now
var index = 0;
var index1 = 0;

//functions add item one at a time to avoid getting a busy script
function oneAdd(singleItem){

	//str is an array made of strings separated by tab
	var str = singleItem.split("\t");

	var num = instances(str[2])
	var inside = str[2] + "-" + num
	var ends = vis.moment(str[0]).add(1, 'seconds');
	//console.log(str[1]);
	items.add([

		{id: inside, title: str[3], content: str[2], start: str[0] , end: ends , className: str[1]}

	]);
}

function oneAdd1(singleItem){

	//str is an array made of strings separated by tab
	var str = singleItem.split("\t");

	//index = index + 1;
	var num = instances(str[2])
	var inside = str[2] + "-" + num
	var ends = vis.moment(str[0]).add(1, 'seconds');
	//document.write(ends);
	items1.add([

		{id: inside, title: str[3], content: str[2], start: str[0] , end: ends , className: str[1]}

	]);
}

//will time base thread the data into the timeline database
ProcessArray(parsedText, oneAdd, Done);
ProcessArray(parsedText, oneAdd1, Done);

// Configuration for the Timeline
var options = {

	autoResize: true,
	itemsAlwaysDraggable: true,
	width: '100%',
	stack: true,
	type: 'box',
	align: 'center',
	selectable: true,
	editable: true,
};

// Create a Timeline
var timeline = new vis.Timeline(container, items, options);

//make the button act when clicked upon
document.getElementById("clickMe").onclick = function(){

	timeline.focus(document.getElementById("id").value);
};

//set the window 2016-01-05T11:35:13.905660
timeline.setWindow('2016-08-05T11:35:05','2016-08-05T11:35:20');

// Create a Timeline
var timeline1 = new vis.Timeline(container1, items1, options);

//set the window 2016-01-05T11:35:13.905660
timeline1.setWindow('2016-08-05T11:35:05','2016-08-05T11:35:20');

//make the button act when clicked upon
document.getElementById("clickMe1").onclick = function(){

	timeline1.focus(document.getElementById("id1").value);
};
