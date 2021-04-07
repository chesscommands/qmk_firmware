# MCU name
MCU = STM32F303
BOARD = QMK_PROTON_C

# Build Options
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically
#
BOOTMAGIC_ENABLE = yes      # Virtual DIP switch configuration
MOUSEKEY_ENABLE = yes      # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = yes         # Console for debug
COMMAND_ENABLE = yes       # Commands for debug and configuration
#NKRO_ENABLE = yes            # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
		# N$B%-!<%m!<%k%*!<%P!<$rM-8z$K$7$?>l9g!"(BBluetooth$B%"%@%W%?$rMQ$$$?$H$-$N5sF0$KLdBj$,H/@8$9$k(B20190721
		# $B$3$l$rL58z$K$7$F$$$k$?$a!"M-8z$K$9$k$9$Y$,$J$/$J$k!#(B
BACKLIGHT_ENABLE = no      # Enable keyboard backlight functionality
MIDI_ENABLE = no            # MIDI controls
AUDIO_ENABLE = yes           # Audio output
UNICODE_ENABLE = no         # Unicode
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
RGBLIGHT_ENABLE = no        # Enable WS2812 RGB underlight.
WS2812_DRIVER = pwm
API_SYSEX_ENABLE = no

# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no    # Breathing sleep LED during USB suspend

#CUSTOM_MATRIX = yes # Custom matrix file
# RGB_MATRIX_ENABLE = WS2812
# SERIAL_LINK_ENABLE = yes
ENCODER_ENABLE = yes
DIP_SWITCH_ENABLE = yes

LAYOUTS = ortho_4x12 planck_mit
LAYOUTS_HAS_RGB = no
