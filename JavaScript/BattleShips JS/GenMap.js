/**@Author Nicholas Ruppel
 * WebApps1 Battleship Project
 * VFS Programming 02
 * Copyright 2015
 */	

var Map = function()
{	
	//this array build the map to place the ships
	this.mapArray=new Array(10);
	
	for(var i=0;i<this.mapArray.length;i++)
	{
		this.mapArray[i] = new Array(10);
	}
	
	
	
	// This places a ship on the map
	this.PlaceShip = function(curShip)
	{
		var isPlaceable =false;
		var shipsx;//x orentation
		var shipsy;//y orentation
		
		while(!isPlaceable)
		{
			//Generate position on map
			if(curShip.orientation==0)
			{
				shipsx=Math.floor(Math.random()*(10-curShip.size));//randomize the x orentation
				shipsy=Math.floor(Math.random()*10);
				
				//Check if position is occupied
				for(var i=0;i<curShip.size;i++)
				{
					//If there is no ship in this position
					if(this.mapArray[shipsx+i][shipsy] == null)
					{
						if(i == curShip.size-1)
						{
							isPlaceable = true;
						}
						continue;
					}
					else
					{
						break;
					}
					
					
				}
				
			}
			//happens if the orentation on the x axis
			else if(curShip.orientation==1)
			{
				shipsx=Math.floor(Math.random()*10);
				shipsy=Math.floor(Math.random()*(10-curShip.size));//randomize the the y orentation
				
				//Check if position is occupied
				for(var i=0;i<curShip.size;i++)
				{
					//If there is no ship in this position
					if(this.mapArray[shipsx][shipsy+i] == null)
					{
						if(i == curShip.size-1)
						{
							isPlaceable = true;
						}
						continue;
					}
					else
					{
						break;
					}
					
					
				}
				
			}
			
			
		}
		
		
		//Place the ship into the array
		//if orientation is up and Down
		if(curShip.orientation==0)
		{
			for(var i=0;i<curShip.size;i++)
			{
				this.mapArray[shipsx+i][shipsy] = 0;
				$('#map' + (shipsx + i) + shipsy).attr("data-ship", curShip.type);
			}
					
		}
		//oreantation is left and right
		 if (curShip.orientation==1)
		{
			for(var i=0;i<curShip.size;i++)
			{
				this.mapArray[shipsx][shipsy+i] = 1;
				$('#map' + shipsx + (shipsy + i)).attr("data-ship", curShip.type);
				
			}	

		}
	}
	//the fleet is set
	this.Setfleet = function(fleet)
	{
		for(var i = 0; i < fleet.ships.length; i++)
		{
			this.PlaceShip( fleet.ships[i])
			
			
			
		}
	}
	
		
	// draws the map that you see
	this.Drawmap = function()
	{

		var mapRowMarkup = "";
		//Create and populate game map tables
		$('#game-map').html("<table id=\"game-table\"></table>");
		for (var i = 0; i < 10; i++) {
		  mapRowMarkup = "<tr>:"; 
		  for (var j = 0; j < 10; j++) {
		    mapRowMarkup += "<td id='map" + i + j; 
		    mapRowMarkup += 	"' data-row='"+i+"' data-col='"+j;
		    mapRowMarkup += 	"' data-ship='0'";
		    mapRowMarkup +=    " class='map-grid'>";
		    mapRowMarkup += "</td>";
		  }	
		  mapRowMarkup += "</tr>";
		  $('#game-table').append( mapRowMarkup );
		}
	};
	
}