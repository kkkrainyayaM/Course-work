#pragma once
#pragma once
//#include "Vector.h"
#include "User.h"
#include "Admin.h"
#include "Employee.h"

namespace DataAccessObject {

	class DAO {
	private:
		Vector<User> users = Vector<User>();
		Vector<Admin> admins = Vector<Admins>();
		static DAO *instance;
		DAO() {}

		void initUserVector();

		void initAdminVector();

	public:
		static DAO* getInstance();

		//Vector<Lot>& getAllLots();

		Admin* getSellerById(int id);

		User* getPartById(int id);

		Lot* getLotById(int id);

		Stavka* getStavkiByIdPart(int id);

		Vector<Stavka> getStavkiByIdLot(int id);

		Stavka* getStavkaById(int id);

		void saveSeller(Admin Admin);

		void saveParticipant(User User);

		void saveLot(Lot lot);

		void writeLotToFile(Lot lot);

		void saveStavka(Stavka stavka);

		void writeStavkaToFile(Stavka stavka);

		void clearStavkiFile();

		void clearLotFile();

		Lot* findByTitle(string title);

		void deleteLotById(int id);

		void deleteStavkaById(int id);

		User* getUserByLogin(string login);

		Vector<Lot> getLotsBySellerId(int id);
	};
}
