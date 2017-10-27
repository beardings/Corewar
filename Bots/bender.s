.name "BENDER"
.comment "small, but ..."

	sti r1, %:lives, %1
	sti r1, %:lives, %6
	sti r1, %:lives, %11
	sti r1, %:lives, %16
	sti r1, %:lives, %21
	sti r1, %:lives, %26
	sti r1, %:lives, %31
	sti r1, %:lives, %43
lives:
	live %1
	live %1
	live %1
	live %1
	live %1
	live %1
	live %1
	ld %0,r2   
	live %1
	zjmp %:lives