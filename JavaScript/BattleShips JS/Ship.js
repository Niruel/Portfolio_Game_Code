/**@Author Nicholas Ruppel
 * WebApps1 Battleship Project
 * VFS Programming 02
 * Copyright 2015
 */	
//this function creates the ship to be placed
function Ship (sName, sSize, sType){
	
	this.name= sName;
	this.size = sSize;
	this.type = sType;
	this.hits = 0;
	this.isSunk = false;
	this.orientation = Math.floor(Math.random() * 2);
	
	// checks if the ship sunk
	this. isSunk = function(){
		return (this.hits == this.size);
	}

	this.getHits = function(){
		
		return this.size;
	}
	
	this.hit = function() {
		this.hits++;
	}
}








































/*
function ship(){
	
	
	function getshiptypefromsize(){
	
	switch (size){
	
	case 1: return "Aircraft Carrier"; break;
	case 2: return "submarine";break;
	case 3: return "destroyer"; break;
	case 4: return "Patrol boat"; break;
	
	default:
		return "battleship";
	break;
	
	}
}
//public methods
	this.shiptype = function(){
		var ships = [
		            "Aircraft Carrier" size= 5,
		            "Submarine", size= 3,
		            "Destroyer", size= 4,
		            "BattleShip", size= 3,
		            "Patrol boat" size= 2
		];
		
		return getshiptypefromsize();
	};

	this.isSunk = function(){
		return ((size - this.hits) < 1);
	};
}
var myship = new ship();
*/