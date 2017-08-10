			D3 Manual and or Guide

Abstract

	Having an interactive and responsive visualization tool helps give life to data. In this case the visualization tool gives the user a nice timeline of flow cell outputs. The timeline can be dragged zoomed into and is searchable. It will give the user an efficient way to search for the information of a specific flow cell, such as its directory, track name, and date. The aim is to reduce time wasted finding information about a specific flow cell in a long list of outputs and files, as well as provide a nice visual to compare different tracks at the same time.

Using the Visualization Tool

	How the visualization tool will be used might depend on a user case basis. The tool here referred to as a timeline, can be thought of as a dynamic scatter plot. Where the x-axis is time and the y-axis are the different tracks the outputs work cells came from. The user can pan through the dates and zoom in on any particular area. The timeline is also searchable. The user can specify the name of the flow cell followed by a dash and the instance number and the timeline will focus on that particular flow cell. An instance number is simply a number which indicates the order of when that particular flow cell was first seen by the timeline. Instance numbers start at 1, for example if the timeline contains a unique name let’s say C7J7XX, it can be searched for by entering C7J7XX-1.

	*Do not press enter, it will resubmit the website.  Click on the focus button displayed on the site.


D3 Intro

	D3 (or D3.js) is a JavaScript library used for visualizing data using web standards. D3 helps you bring data to life using SVG, Canvas and HTML. D3 combines powerful visualization and interaction techniques with a data-driven approach to DOM manipulation, giving you the full capabilities of modern browsers and the freedom to design the right visual interface for your data. (D3 ReadMe)

	D3 Cite: https://github.com/d3/d3/blob/master/README.md

Requirements to edit the website

	-D3 library’s (Called directly or downloaded)
	-Text editor
	-A browser that allows local files such as Firefox
	-The Visualization Timeline repo

The Framework

	The D3 framework is a fairly light weight library. There are two ways of using the D3.js library. The first is to download and install the library from the D3 website. The second and the most efficient way is to directly load from d3js.org, that way the timeline website will always load the most up to date D3 library. The D3 library is extremely versatile and used to create range of different visuals and visual effects used to display data. The API and other references can be found on the link above.

The Software

	The website is composed of 3 major files:  "scatter.js", "scatter.css", and "index.html. It gathers data from a tab separate values file named "example_input.tsv". The example_input file is generated and updated every time the "generate_data.py" script is called. All of these files along with images for customization purposes are located in the D3 folder of the Visualization Timeline repo.

Link: git@gitlab.com:Manny500/Visualization_Timeline.git

JS

	JavaScript is a programming language that is run by most modern browsers. It supports object oriented programming and procedural programming. It is mainly used to control web pages on the client side of the browser, server-side programs, and even mobile applications.
	
	scatter.js is where most of the website's source code is located. The file is a mixture of the typical JavaScript language along with D3 JavaScript methods. This is where the data file is parsed. D3 has a convenient method called d3.tsv that is able to store the whole file/data into a container. The data can be retrieved calling the container, but not necessarily iterable, in order to access the data functionally one has to bind the data in the container with an associated "title". Every time that title is called it iterates through the data that was binded with that title. This could be done  one iteration at a time or loop through all the binded data with a for loop.

	The js file's main goal is to make an interactive canvas. It defines the scalability of the canvas's axis and their range. It enables the graph/plot to tranformed, this enables the graph and its contents to be zoomed and paned. Most of the transformations happen with the translation function D3 provides. Translate is able to calculate the new positon of the graph axisis and the plots plotted.

CSS

	CSS stands for Cascading Style Sheets. CSS defines and describes how HTML element should be have or how they are to be displayed on the screen, paper, or in any other media. It can save a lot of working by controling multiple web pages all at once.
	
	scatter.css is where all the customization for the D3 timeline is described. It specifies the background of the website, describes the font for the text and its color. It is also describes the position of all the images, buttons, and forms.

HTML

	HTML stands for Hypertext Markup Language; it is a standardized system for tagging text files to achieve a desired font, color, graphic, and hyperlink effect on World Wide Web pages.
	
	index.html is named index and not any other name, such as scatter.html, because the defaults file to go to when accessing a folder in a browser - in particularly when hosted on a server - is index.html. In this case the index file doesn’t have much text. It specifies the title of the website and form titles. The main importance of it is that it is the file that combines everything together through references. It links CSS and JS files together with images and itself.

References

	Git Repo: git@gitlab.com:Manny500/Visualization_Timeline.git

	D3 Website: https://github.com/d3/d3/blob/master/README.md

	D3 Scripts: <script src="https://d3js.org/d3.v4.0.0-alpha.50.min.js"></script>

	Website link: http://rd-serv.amdx.local/visualize/D3/
