/**@Author Nicholas Ruppel
 * WebApps1 Battleship Project
 * VFS Programming 02
 * Copyright 2015
 */	
var game = (function(){
	
	function GameSingleton()
	{
		var myGameTitle="Battleship";
		//sounds
		var gameMusicLoop = new buzz.sound("Sounds/mus_battleloop", {formats: ["wav"], loop: true});

		var ammo = 50;
		var score = 0;
	
	
		var local = 
		{
			//In here we create our private properties
			myMap : []
		};
		
		local.myFleet = new Fleet();
		
		local.update = function()
		{
			
			
		};
		
		local.render = function()
		{
			
			
		};
		
		local.initGameMap = function()
		{
			myMap = new Map();
			myMap.Drawmap();
			myMap.Setfleet(local.myFleet);
			console.log(myMap.mapArray);

		};
		// performs the hits on a ship if the player hits a ship
		local.performHit = function(shipType) 
		{

			console.log(shipType);
			//adds the hits to a wounded ship
			local.myFleet.ships[shipType-1].hits++;
				
			if(local.myFleet.ships[shipType-1].hits==local.myFleet.ships[shipType-1].size)
			{
				local.myFleet.ships[shipType-1].isSunk=true;//sink a the current ship in bthe fleet
				
				
			}
			
		};
	
		// deals with when a user clicks
		local.initHandlers = function()
		{
			
		
			$('.map-grid').click(function()
			{
				var clickedX = parseInt($(this).data("row"));
				var clickedY = parseInt($(this).data("col"));
				var shipHit = parseInt($(this).data("ship"));
				var gameHits = new buzz.sound("Sounds/Hit", {formats: ["wav"], loop: false});	
				var gameMiss = new buzz.sound("Sounds/clickmenu", {formats: ["wav"], loop: false});
				ammo--;//decrement the shots the user has left
				$('#misslecount').html("<h1>" + ammo + "</h1>");
			
					
				//this changes the color of tile and keep record of hits 
				if(shipHit != 0 && shipHit != undefined)
				{
					$('#map' + clickedX + clickedY).addClass("hit");// indicates a hit on the map
					
				
					
					
					score++;//increment score by one
					$('#scorecount').html("<h1>" + score + "</h1>");// updates score by one
					gameHits.play();//plays hit sounds
					//check to see if ship is dead then make picture disappear
						
							
							$("#ship" +  shipHit).hide();
						
					
					
				
				}
				
				else  
				{
					//changes color to white to indicate miss and keep record of misses
					$('#map' + clickedX + clickedY).addClass("miss");
					gameMiss.play();//plays miss sound

				}
				
			});
			
		}
		

		
		
		this.init = function()
		{
			//Initialization code for game goes here
		
			local.initGameMap();
			local.initHandlers();
			gameMusicLoop.play();//plays the action music

			
			
		};
		
		this.run = function()
		{
			//code that runs the game
			local.update();
			local.render();
		};
	}
	
	return new GameSingleton();
})();
// this runs the code
$(document).ready(function(){
	game.init();
	game.run();
});