public class MemberOfParliament
{
    private string name;
    private string constituency;
    private string party;

    public MemberOfParliament(string name, string constituency, string party)
    {
        this.name = name;
        this.constituency = constituency;
        this.party = party;
    }

    public string Name
    {
        get { return name; }
        set { name = value; }
    }

    public string Constituency
    {
        get { return constituency; }
        set { constituency = value; }
    }

    public string Party
    {
        get { return party; }
        set { party = value; }
    }
}
