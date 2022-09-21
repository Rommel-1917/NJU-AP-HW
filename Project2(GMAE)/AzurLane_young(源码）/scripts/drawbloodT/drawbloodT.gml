// Script assets have changed for v2.3.0 see
// https://help.yoyogames.com/hc/en-us/articles/360005277377 for more information
function drawbloodT(max_hp,now_hp){

draw_set_color(c_green)
draw_rectangle(x-125,y+50,x+125,y+75,1)
draw_rectangle(x-125,y+50,x+cal(max_hp,now_hp),y+75,0)
draw_set_color(c_white)
}
