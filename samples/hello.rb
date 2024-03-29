#
# Sample script for mruby on Yet Another Bare Metal
#

begin

yabm = YABM.new

yabm.print "Hello Bear Metal mruby on YABM"

yabm.watchdogstart(30)

loop do
   yabm.print "."
   yabm.msleep 500
   yabm.watchdogreset
end

rescue => e
  yabm.print e.to_s
end
