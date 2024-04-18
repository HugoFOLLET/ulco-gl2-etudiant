import gi
import math

import tictactoe

gi.require_version("Gtk", "3.0")
from gi.repository import Gtk, Gdk

class Gui(Gtk.Window):
	
	def __init__(self):
		super().__init__(title="Tictactoe")
		self.set_size_request (400, 400)

		# main vertical box : drawing area + hbox (label, button1, button2)
		vbox = Gtk.Box(orientation=Gtk.Orientation.VERTICAL)
		self.add(vbox)

		# drawing area
		self.drawingarea = Gtk.DrawingArea()
		self.drawingarea.add_events(Gdk.EventMask.BUTTON_PRESS_MASK)
		self.drawingarea.connect("draw", self.on_draw)
		self.drawingarea.connect("button-press-event", self.on_area_button_press)
		vbox.pack_start(self.drawingarea, True, True, 0)

		# horizontal box
		hbox = Gtk.Box()
		vbox.pack_end(hbox, False, False, 0)
		# label
		self.label = Gtk.Label(label="LABEL")
		hbox.pack_start(self.label, True, True, 0)
		# TODO button1
		button1 = Gtk.Button(label="Rejouer")
		button1.connect("clicked", self.on_button1_clicked)
		hbox.pack_start(button1, True, True, 0)
		# button2
		button2 = Gtk.Button(label="Quitter")
		button2.connect("clicked", self.on_button2_clicked)
		hbox.pack_start(button2, True, True, 0)

		# TODO create game (from the C++ module)
		self.j = tictactoe.Jeu()
		self.label.set_text(self.j.showStatus(self.j.getStatus()))
		self.circles=[]

	def on_draw(self, widget, context):
		width = widget.get_allocated_width()
		height = widget.get_allocated_height()

		context.set_source_rgb(0, 0, 0)
		context.rectangle(0, 0, 399, 399)
		context.fill()

		context.set_source_rgb(0.5, 0.5, 0.5)
		context.set_line_width(3)
		i=1
		while (i<3):
			context.move_to((width/3)*i, 0)
			context.line_to((width/3)*i, height)

			context.move_to(0,(height/3)*i)
			context.line_to(width, (height/3)*i)
			i=i+1

		for point in self.circles:
			context.set_source_rgb(255,255,255)
			context.arc(point[0], point[1], (width/3)/2, 0, 2*math.pi)
			context.fill()
		
		context.stroke()
	

	def draw_circle(self, widget, i, j):
		x=0
		y=0
		width = widget.get_allocated_width()
		height = widget.get_allocated_height()
		context = widget.connect.context
		if(i>0 and i<(width/3)):
			x=(width/3)/2
		elif(i>(width/3) and i<(2*width/3)):
			x=(width/3)+((width/3)/2)
		else:
			x=width-(width/3)
		
		if(j>0 and j<(width/3)):
			y=(width/3)/2
		elif(j>(width/3) and j<(2*width/3)):
			y=(width/3)+((width/3)/2)
		else:
			y=width-(width/3)
		
		self.circles.append([x,y])

		drawing_area.queue_draw()

		#drawing_area.set_source_rgb(255,255,255)
		#drawing_area.arc(x, y, (width/3)/2, 0, 2*math.pi)
		#drawing_area.fill()
		#drawing_area.stroke()


	def on_area_button_press(self, widget, event):
		# TODO on_area_button_press
		self.label.set_text(self.j.showStatus(self.j.getStatus()))
		if event.button == 1:
			self.draw_circle(widget,event.x,event.y)
			print(event.x)
			print('TODO on_area_button_press')
			

	def on_button1_clicked(self, widget):
		self.j.raz()
		print('TODO on_button1_clicked')
		self.drawingarea.queue_draw()

	def on_button2_clicked(self, widget):
		Gtk.main_quit()

if __name__ == '__main__':
	gui = Gui()
	gui.connect("destroy", Gtk.main_quit)
	gui.show_all()
	Gtk.main()

