
awk '
BEGIN {
	if("xyz" > "abcdefgh")
		print "xyz greater than abcdefgh"
	else 
		print "abcdefgh greater than xyz"

	if("" > "abcdefgh")
		print "null str greater than abcdefgh"
	else 
		print "abcdefgh greater than null str"

	if("xyz" > 12345)
		print "xyz greater than num 12345"
	else 
		print "num 12345 greater than xyz"

	if("xyz" > "12345")
		print "xyz greater than quoted 12345"
	else 
		print "quoted 12345 greater than xyz"

	if("+xyz" > "12345")
		print "+xyz greater than quoted 12345"
	else 
		print "quoted 12345 greater than +xyz"

	if("<xyz" > "12345")
		print "<xyz greater than quoted 12345"
	else 
		print "quoted 12345 greater than <xyz"

	if( 12345 > "")
		print "num 12345 greater than null str "
	else 
		print "null str  greater than 12345"


}
'
