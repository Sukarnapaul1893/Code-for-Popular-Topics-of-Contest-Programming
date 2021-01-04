inline ll mul(ll a, ll b) {
	a %= mod, b %= mod;
	return (a * b) % mod;
}
 
inline ll add(ll a, ll b) {
	a %= mod, b %= mod;
	return (a + b) % mod;
}
 
inline ll sub(ll a, ll b) {
	a %= mod, b %= mod;
	a -= b;
	a+=mod; a%=mod;
	return a;
}
