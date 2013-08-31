// AEPositionExporter.jsx

var fileName;
var file = null;
var comp = app.project.activeItem;

function getFileName()
{
	fileName = prompt("Please input a file name.", "file");

	if (fileName == null) return;

	if (fileName.indexOf(".plist") == -1)
		file = new File(fileName + ".plist");
	else
		file = new File(fileName);
}

function exportPositionData(comp) 
{
	var layers = comp.layers;

	if (file == null) return;

	if (file.open("w")) {

		file.writeln('<?xml version="1.0" encoding="UTF-8"?>');
		file.writeln('<!DOCTYPE plist PUBLIC "-//Apple Computer//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">');
		file.writeln('<plist version="1.0">');
		file.writeln('<dict>');

		for (var i = 1; i <= comp.numLayers; i++) {
			var layer = layers[i];
			var time  = layer.inPoint;
			var position =  layer.transform.position.valueAtTime(time, false);

			// key = imageName
			file.writeln('	<key>' + layer.name + '</key>');
			file.writeln('	<string>{' + position[0] + ',' + position[1] + '}</string>');
		};

		file.writeln('</dict>');
		file.writeln('</plist>');

		file.close();
	}
}

getFileName();
exportPositionData(comp);
