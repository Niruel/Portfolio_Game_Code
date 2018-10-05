/**
 * 
 */
function PerformHit() {
	var gameAmmo = 50;
	var isHit = false;
	
	if(!isHit){
		curship.hits++;
		
		if(curship.hits==curship.size){
			curship.isSunk=true;
		}
		
	}
	
	
}