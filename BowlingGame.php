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
		$FrameIndex = 0;
		
		for($frame = 0; $frame < 10; $frame++){
			if($this->isStrike(FrameIndex)){
				$score += 10 + $this -> nextTwoRoundsStrike($FrameIndex);
				$FrameIndex++;
			}else if($this->isSpare($FrameIndex){
				$score += 10 + $this -> nextRoundSpare($FrameIndex);
				$FrameIndex += 2;
			}else{
				$score += $this -> nextRound($FrameIndex);
				$FrameIndex += 2;
			}
		}
		return $score;
	}
	// Decide whether it's a strike
	//if the FrameIndex is 10, return true
	private function isStrike($FrameIndex){
		return $this -> rolls[$FrameIndex] == 10;
	}
	// decude whether it's a spare
	// if the first two frames sums up to 10, return true
	private function isSpare($FrameIndex){
		return $this -> rolls[$FrameIndex] + rolls[$FrameIndex + 1] == 10;
	}
	
	// the next two rounds are all strike
	private function nextTwoRoundsStrike($FrameIndex){
		return $this ->rolls[$FrameIndex + 1] + rolls[$FrameIndex + 2];
	}
	
	// the next round is Spare
	private function nextRoundSpare($FrameIndex){
		return $this -> rolls[$FrameIndex + 2];
	}
	
	// neither strike or spare, add the score together
	private function nextRound($FrameIndex){
		return $this -> rolls[$FrameIndex] + rolls[$FrameIndex + 1];
	}
	
?>
