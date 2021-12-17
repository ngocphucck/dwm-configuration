#!/bin/dash

# ^c$var^ = fg color
# ^b$var^ = bg color

interval=0

# load colors!
. ~/.config/dwm-6.2/bar/themes/onedark

cpu() {
	cpu_val=$(grep -o "^[^ ]*" /proc/loadavg)

	printf "^c$black^ ^b$green^ CPU"
	printf "^c$white^ ^b$grey^ $cpu_val"
}

pkg_updates() {
	#updates=$(doas xbps-install -un | wc -l) # void
	# updates=$(checkupdates | wc -l)   # arch , needs pacman contrib
	 updates=$(apt-cache search '~U' | wc -l)  # apt (ubuntu,debian etc)

	if [ "$updates" = 0 ]; then
		printf "^c$blue^  Fully updated"
	else
		printf "^c$red^  $updates"" updates"
	fi
}

battery() {
	get_capacity="$(cat /sys/class/power_supply/BAT0/capacity)"
	status="$(cat /sys/class/power_supply/BAT0/status)"

	if [ "$status" = "Charging" ]; then
		printf "^c$green^   $get_capacity"
	elif [ $get_capacity -ge 90 ]; then
		printf "^c$green^   $get_capacity"
	elif [ $get_capacity -ge 70 ]; then
		printf "^c$green^   $get_capacity"
	elif [ $get_capacity -ge 50 ]; then
		printf "^c$yellow^   $get_capacity"
	elif [ $get_capacity -ge 20 ]; then
		printf "^c$yellow^   $get_capacity"
	else
		printf "^c$red^   $get_capacity"
	fi
}

brightness() {
	printf "^c$red^   "
	printf "^c$red^%.0f\n" $(cat /sys/class/backlight/*/brightness)
}

mem() {
	printf "^c$green^^b$black^  "
	printf "^c$green^ $(free -h | awk '/^Mem/ { print $3 }' | sed s/i//g)"
}

wlan() {
	case "$(cat /sys/class/net/w*/operstate 2>/dev/null)" in
	up) printf "^c$black^ ^b$blue^   ^d^%s" " ^c$blue^Connected" ;;
	down) printf "^c$black^ ^b$blue^ 睊  ^d^%s" " ^c$blue^Disconnected" ;;
	esac
}

clock() {
	printf "^c$black^ ^b$darkblue^  "
	printf "^c$black^^b$blue^ $(date '+%I:%M %p') "
}

while true; do

	[ $interval = 0 ] || [ $(($interval % 3600)) = 0 ] && updates=$(pkg_updates)
	interval=$((interval + 1))

	xsetroot -name "$updates $(battery) $(wlan) $(mem) $(clock)" && sleep 1
done
