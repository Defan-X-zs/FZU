friend istream& operator >> (istream&, point&);
istream& operator >> (istream& in,point& p)
{
	in>>p.a>>p.b>>p.c;
	return in;
}