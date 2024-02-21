import Logger as log
from datetime import datetime

if __name__ == '__main__':

	logg = log.Logger()
	lev1 = log.Level.Info
	lev2 = log.Level.Error

	logg.add_item(lev1, "Une info",datetime.now().strftime("%Y-%m-%d %H:%M:%S"))
	logg.add_item(lev2, "Une erreur",datetime.now().strftime("%Y-%m-%d %H:%M:%S"))
	logg.add_item(log.Level.Info,"Une autre info",datetime.now().strftime("%Y-%m-%d %H:%M:%S"))
	logg.add_item(log.Level.Warning,"Un avertissement",datetime.now().strftime("%Y-%m-%d %H:%M:%S"))

	print("**** report_by_added ****")
	print(logg.report_by_added())

	print("**** report_by_level ****")
	print(logg.report_by_level())

