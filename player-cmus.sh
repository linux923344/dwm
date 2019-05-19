# #!/bin/sh

# if info=$(cmus-remote -Q 2> /dev/null); then
# 	status=$(echo "$info" | grep status | awk -F\  '{print $2}')
	
# 	file=$(echo "$info" | grep file | awk -F\  '{print $2}')
	
# 	if [ "$status" = "playing" ] || [ "$status" = "paused" ]; then
# 		title=$(echo "$info" | grep title | awk -F\  '{$1=$2=""; print $0}' | sed 's|^[[:blank:]]*||g')
# 		artist=$(echo "$info" | grep '[[:space:]]artist' | awk -F\  '{$1=$2=""; print $0}' | sed 's|^[[:blank:]]*||g')
# 		position=$(echo "$info" | grep position | awk -F\  '{print $2}')
# 		duration=$(echo "$info" | grep duration | awk -F\  '{print $2}')
		
# 		pos_minutes=$(printf "%02d" $(("$position" / 60)))
# 		pos_seconds=$(printf "%02d" $(("$position" % 60)))

# 		dur_minutes=$(printf "%02d" $(("$duration" / 60)))
# 		dur_seconds=$(printf "%02d" $(("$duration" % 60)))

# 		stream=$(cmus-remote -Q | grep stream | sed -e 's/stream\>//g')
# 		tag=$(cmus-remote -Q | grep "tag title" | sed -e 's/tag title\>//g')
		
# 		radioTurn=0
# 		if [ "$file" = "http://sky1.torontocast.com:9041/.mp3" ]; then
# 			echo "  $stream"
# 			radioTurn=1
# 		fi

# 		if [ "$tag" = " Radio ZET" ]; then
# 			echo "  Radio ZET"
# 			radioTurn=1
# 		fi
		
		
		
# 		if [ "$radioTurn" = "0" ]; then
# 			#echo "    $pos_minutes:$pos_seconds / $dur_minutes:$dur_seconds"
# 			echo "    $pos_minutes:$pos_seconds / $dur_minutes:$dur_seconds"
# 			#echo "   $artist - $title | $pos_minutes:$pos_seconds / $dur_minutes:$dur_seconds"
# 		elif [ "$status" = "paused" ]; then
# 			#echo ""
# 			echo "    $pos_minutes:$pos_seconds / $dur_minutes:$dur_seconds"
# 		else
# 			echo ""
# 		fi
# 	else
# 		echo ""
# 	fi
# else
# 	echo ""
# fi

#!/bin/sh

if info=$(cmus-remote -Q 2> /dev/null); then
	status=$(echo "$info" | grep status | awk -F\  '{print $2}')
	
	file=$(echo "$info" | grep file | awk -F\  '{print $2}')
	
	if [ "$status" = "playing" ] || [ "$status" = "paused" ]; then
		title=$(echo "$info" | grep title | awk -F\  '{$1=$2=""; print $0}' | sed 's|^[[:blank:]]*||g')
		artist=$(echo "$info" | grep '[[:space:]]artist' | awk -F\  '{$1=$2=""; print $0}' | sed 's|^[[:blank:]]*||g')
		position=$(echo "$info" | grep position | awk -F\  '{print $2}')
		duration=$(echo "$info" | grep duration | awk -F\  '{print $2}')
		
		pos_minutes=$(printf "%02d" $(("$position" / 60)))
		pos_seconds=$(printf "%02d" $(("$position" % 60)))

		dur_minutes=$(printf "%02d" $(("$duration" / 60)))
		dur_seconds=$(printf "%02d" $(("$duration" % 60)))

		stream=$(cmus-remote -Q | grep stream | sed -e 's/stream\>//g')
		tag=$(cmus-remote -Q | grep "tag title" | sed -e 's/tag title\>//g')
		
		radioTurn=0

		if [ "$radioTurn" = "0" ]; then
			#echo "    $pos_minutes:$pos_seconds / $dur_minutes:$dur_seconds"
			echo "    $pos_minutes:$pos_seconds / $dur_minutes:$dur_seconds"
			#echo "   $artist - $title | $pos_minutes:$pos_seconds / $dur_minutes:$dur_seconds"
		elif [ "$status" = "paused" ]; then
			#echo ""
			echo "    $pos_minutes:$pos_seconds / $dur_minutes:$dur_seconds"
		else
			echo ""
		fi
	else
		echo ""
	fi
else
	echo ""
fi

