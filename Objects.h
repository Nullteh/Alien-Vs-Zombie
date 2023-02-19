class health : public Objects
	{
		public:
			health();
			health(const int point);
			int getHealingPoint() const;
			virtual void encounterEvent(Alien& alien);
		private:
			int healingPoint;
	};

class Arrow : public Objects
	{
		public:
			arrow();
			arrow(const int attackPower, const char _symbol);
			arrow(Arrow&);
			//virtual ~Arrow();
			int getAttackPower() const;
			virtual void encounterEvent(Alien& alien);
		private:
			int attackPower;
			
	};

class Rock : public Objects
	{
		public:
			Rock();
			//virtual ~Rock();
			virtual void encounterEvent(Alien& alien);
			virtual Objects& reveal();
		protected:
			bool flipped;
			Objects& discovered();
		
		private:
			
	};