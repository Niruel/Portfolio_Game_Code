/**@Author Nicholas Ruppel
 * WebApps1 Battleship Project
 * VFS Programming 02
 * Copyright 2015
 */	
//this creates the whole fleet to placed
var Fleet = function (){
	// Build the fleet

	this.ships = [
	                new Ship("AirCraft Carrier", 5, 1),
	                new Ship("BattleShip", 4, 2),
	                new Ship("Sub", 3, 3),
	                new Ship("Cruiser", 3, 4),
	                new Ship("Destroyer", 2, 5)

	];
	
	//Return the fleet
};