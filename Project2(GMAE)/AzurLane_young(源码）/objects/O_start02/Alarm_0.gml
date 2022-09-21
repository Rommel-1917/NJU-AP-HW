/// @description Insert description here
// You can write your code in this editor
if(flag_count<flag_amount)
{
	instance_create_depth(x,y,-1,O_smasher)
	
	
	flag_count++;
	alarm[0]=flag_rate*4;
}
else
{
	global.flags++
}

