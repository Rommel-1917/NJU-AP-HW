/// @description Insert description here
// You can write your code in this editor
if(flag_count<flag_amount)
{
	instance_create_depth(x,y,-1,O_fly)
	
	
	flag_count++;
	alarm[0]=flag_rate*2;
}else
{
	global.flags++
}

