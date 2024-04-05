#include <hv/WebSocketServer.h>

#include <list>
#include <thread>

class Net {
	private:
		std::list<WebSocketChannelPtr> _channels;

		// pour gérer les noms de client :
		std::list<WebSocketChannelPtr> _pendings;
		std::map<WebSocketChannelPtr, std::string> _connections;

	public:
		Net() = default;
		Net(const Net &) = delete;

		void add(const WebSocketChannelPtr & c) {
			_channels.push_front(c);
			_pendings.push_front(c);
		}

		void del(const WebSocketChannelPtr & c) {
			auto it = std::find(_channels.begin(), _channels.end(), c);
			if (it != _channels.end())
				_channels.erase(it);
			
			for(auto p=_pendings.begin();p!=_pendings.end();p++){
				if(*p==c){
					_pendings.erase(p);
				}
			}
			if(auto ptr=_connections.find(c); ptr!=_connections.end()){
				_connections.erase(ptr);
			}
		}

		void map(std::function<void(const WebSocketChannelPtr &)> f) {
			for (const WebSocketChannelPtr & c : _channels)
				f(c);
		}

		// pour gérer les noms de client :
		bool giveName(const WebSocketChannelPtr& c, const std::string& n){
			if(auto it = _connections.find(c); it!=_connections.end()){
				return false;
			}
			_connections[c]=n;
			for(auto it=_pendings.begin();it!=_pendings.end();it++){
				if(*it==c){
					_pendings.erase(it);
					return true;
				}
			}
			return true;
		}
		bool isPending(const WebSocketChannelPtr& c) const{
			for(auto it=_pendings.begin();it!=_pendings.end();it++){
				if(*it==c){
					return true;
				}
			}
			return false;
		}
		std::string findName(const WebSocketChannelPtr& c) const{
			if(auto it = _connections.find(c); it!=_connections.end()){
				return it->second;
			}
			return "Default";
		}

};

