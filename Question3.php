<?php


$input ="";
$state="";
	

$input_arr=array("0c","5c","10c");
$input_val= array(0,5,10);
$state_arr=array("No coin","Sum is 5","Sum is 10","Vend");
static $total_sum=0;

$input=$input_val[0];
$state=$state_arr[0];

function run($input,$state,$input_arr,$state_arr,$input_val){

switch($state){
	case $state_arr[0]: echo"Current state is $state_arr[0] state";
echo"\n";
				switch($input){
				case $input_arr[0]: echo "You entered $input_arr[0] into the machine\n\t";
						   $total_sum+= $input_val[0];				
						   echo "Moving to the new state $state_arr[0]";
						   $state=$state_arr[0];
						   $input=$input_val[rand(0,3)];
                                                       run($input,$state,$input_arr,$state_arr,$input_val);
							break;	
				case $input_arr[1]: echo "You entered $input_arr[1] into the machine\n\t";
						   $total_sum+= $input_val[1];				
						   echo "Moving to the new state $state_arr[1]" ;
							$state=$state_arr[1];
						   $input=$input_val[rand(0,3)];
							break;
				case $input_arr[2]: echo "You entered $input_arr[2] into the machine\n\t"  ;
						   $total_sum+= $input_val[2];				
						   echo "Moving to the new state $state_arr[2]" ;
							$state=$state_arr[2];
						   $input=$input_val[rand(0,3)];
							break;
					}
				break;
	case $state_arr[1]:switch($input){
				case $input_arr[0]: echo "You entered $input_arr[0] into the machine\n\t" ;
						   $total_sum+= $input_val[0];				
						   echo "Moving to the new state $state_arr[1]" ;
						   $state=$state_arr[1];
						   $input=$input_val[rand(0,3)];
							break;	
				case $input_arr[1]: echo "You entered $input_arr[1] into the machine\n\t" ;
						   $total_sum+= $input_val[1];				
						   echo "Moving to the new state $state_arr[2]" ;
							$state=$state_arr[2];
						   $input=$input_val[rand(0,3)];
							break;
				case $input_arr[2]: echo "You entered $input_arr[2] into the machine\n\t" ;
						   $total_sum= $input_val[0];
							echo "Here is your bottle of coke...\n\n\n\t" ;				
						   echo "Moving to the new state $state_arr[0]" ;
							$state=$state_arr[0];
						   $input=$input_val[rand(0,3)];
							break;
					}
				break;
	case $state_arr[2]:switch($input){
				case $input_arr[0]: echo "You entered $input_arr[2] into the machine\n\t" ;
						   $total_sum+= $input_val[0];				
						   echo "Moving to the new state $state_arr[2]" ;
						   $state=$state_arr[2];
						   $input=$input_val[rand(0,3)];
							break;	
				case $input_arr[1]: echo "You entered $input_arr[1] into the machine\n\t" ;
						   $total_sum= $input_val[0];				
							echo "Here is your bottle of coke...\n\n\n\t" ;
						   echo "Moving to the new state $state_arr[0]" ;
							$state=$state_arr[0];
						   $input=$input_val[rand(0,3)];
							break;
				case $input_arr[2]: echo "You entered $input_arr[2] into the machine\n\t" ;
						   $total_sum= $input_val[1];
							echo "Here is your bottle of coke...\n\n\n\t" ;				
						   echo "Moving to the new state $state_arr[1]" ;
							$state=$state_arr[1];
						   $input=$input_val[rand(0,3)];
							break;
				



				break;	

}


}
}






function run($input,$state,$input_arr,$state_arr,$input_val)

?>		
