if(global.health<=0)
{
	audio_stop_sound(play);
room_goto(lose)
}
else if(global.flags==4 or global.coins>=200)
{
	audio_stop_sound(play);
	room_goto(win)
}
