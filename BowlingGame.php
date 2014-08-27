<? php

class BowlingGame
{
	private $rolls = array();
	public function roll($pins){
		$this->rolls[] = $pins;
	}
	// main function to get the score for each frame
	public function get_Score(){
		$score = 0;
		$frameIndex = 0;
		
		for($frame = 0; $frame < 10; $frame++){
			if($this->isStrike($frameIndex)){
				$score += 10 + $this -> nextTwoRoundsStrike($frameIndex);
				$frameIndex++;
			}else if($this->isSpare($frameIndex){
				$score += 10 + $this -> nextRoundSpare($frameIndex);
				$frameIndex += 2;
			}else{
				$score += $this -> nextRound($frameIndex);
				$frameIndex += 2;
			}
		}
		return $score;
	}
	// Decide whether it's a strike
	//if the frameIndex is 10, return true
	private function isStrike($frameIndex){
		return $this -> rolls[$frameIndex] == 10;
	}
	// decude whether it's a spare
	// if the first two frames sums up to 10, return true
	private function isSpare($frameIndex){
		return $this -> rolls[$frameIndex] + rolls[$frameIndex + 1] == 10;
	}
	
	// the next two rounds are all strike
	private function nextTwoRoundsStrike($frameIndex){
		return $this ->rolls[$frameIndex + 1] + rolls[$frameIndex + 2];
	}
	
	// the next round is Spare
	private function nextRoundSpare($frameIndex){
		return $this -> rolls[$frameIndex + 2];
	}
	
	// neither strike or spare, add the score together
	private function nextRound($frameIndex){
		return $this -> rolls[$frameIndex] + rolls[$frameIndex + 1];
	}
	// turkey bonus
	public function turkeyBonus(){
		for($frame = 0; $frame < 10; $frame++){
			if($this -> isStrike($frame) && $this -> isStrike($frame + 1){
				echo "Turkey Bonus!";
				return $frame + 1;
			}
		}
	}
	
?>
