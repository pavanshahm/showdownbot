class Decision:
	def __init__(self):
		self.this = new_Decision()
	def __del__(self):
		delete_Decision(self.this)
	def makeDecision(self, info):
		return Decision_makeDecision(self.this, info);