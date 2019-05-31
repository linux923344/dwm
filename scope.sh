# Ascii-previews of images:
image/*)
    img2txt --gamma=0.6 --width="$width" "$path" && exit 4 || exit 1;;
