inline void normal(ll& a) {
	a %= mod;
	(a < 0) && (a += mod);
}

inline ll mul(ll a, ll b) {
	a %= mod, b %= mod;
	normal(a), normal(b);
	return (a * b) % mod;
}

inline ll add(ll a, ll b) {
	a %= mod, b %= mod;
	normal(a), normal(b);
	return (a + b) % mod;
}

inline ll sub(ll a, ll b) {
	a %= mod, b %= mod;
	normal(a), normal(b);
	a -= b;
	normal(a);
	return a;
}
