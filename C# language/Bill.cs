public class Bill : IVotable
{
    private string title;
    private string status;
    private int votes;
    private int billId;

    public Bill(string title, int billId, string status)
    {
        this.title = title;
        this.status = status;
        this.billId = billId;
        this.votes = 0;
    }

    public string Title
    {
        get { return title; }
        set { title = value; }
    }

    public string Status
    {
        get { return status; }
        set { status = value; }
    }

    public int Votes
    {
        get { return votes; }
        set { votes = value; }
    }

    public int BillId
    {
        get { return billId; }
        set { billId = value; }
    }

    public void Vote()
    {
        Console.WriteLine("Voting on bill '" + title + "'");
        votes++;
    }
}
