$(document).ready(function(){
	
	form_init();
	comments_init();
	list_books();
	dropdown_init();
	search_init();
	
});



function search_init() {
	$("#search_input").keyup(function() {
		var query = $("#search_input").val();
		if (query == "") {
			$("tr.bookrow").show();
		}
		else {
			$("tr.bookrow").hide();
			var selector = "p." + query.toLowerCase();
			$(selector).parent().parent().show();
		}
	});
}




function dropdown_init() {
	$("#controlsclickhere").click(function(){
		$(this).hide();
		$(".controlspopup").show();
		$("input#title").select();
	});
}



function create_X(domelement) {
	var newdiv = $("<div>").addClass("remove");
	newdiv.click(function(){
		var parent = $(this).parent();
		var book_uid = parent.attr("book_uid");
		var comment_uid = parent.attr("comment_uid");
		if (!comment_uid) {
			$.post("removebook.php", 
				{book_uid: book_uid}, 
				function(data) {
					$("tr[class='bookrow'][book_uid='" + book_uid + "']").remove();
				}, "json");
		}
		else {
			$.post("removecomment.php", 
				{comment_uid: comment_uid}, 
				function(data) {
					var commentcontainer = $("div[class='comments_one'][book_uid='" + book_uid + "'][comment_uid='" + comment_uid + "']");
					commentcontainer.slideUp(function(){
						$(this).remove();
					});
				}, "json");	
		}
	});
	newdiv.text("X");
	domelement.append(newdiv);
}


/* get form data on clicking add and process data */
function form_init() {
	$("form#controls_form").submit(function(){
		
		var title = $("input#title").val();
		var author = $("input#authors").val();
		var image_url = $("input#imageurl").val();
	
		/* validate inputs--only add to page if validated */
		if (title.length == 0 || title.length > 127) {
			alert("Error: Titles need to be 1-127 characters in length");
			return false;
		}
		if (author.length == 0 || author.length > 127) {
			alert("Error: Authors need to be 1-127 characters in length");
			return false;
		}
		if (image_url.length > 512) {
			alert("Error: Image URLs need to be less than 512 characters in length");
			return false;
		}
		
		/* place the new book on the page, send request to put in DB */
		$.post("addbook.php", 
			{author: author, title: title, image_url: image_url}, 
			function(data) {
				add_book(title, author, image_url, data[0].uid);
			}, "json");
		
		/* clear forms after submitting */
		$("input#title").val("");
		$("input#authors").val("");
		$("input#imageurl").val("");
		
		$("input#title").select();
		/* make form not submit */
		return false;
	});
}



/* add listeners for clicking on viewing comments */
function comments_init() {
	
	/* make comments appear */
	$(".seecomments").live("click",function(){
		$(this).parent().parent().find("div.comments").show();
		$(this).parent().find("a.hidecomments").show();
		$(this).hide();
		return false;
	});
	
	/* make comments disappear */
	$(".hidecomments").live("click",function(){
		$(this).parent().parent().find("div.comments").hide();
		$(this).parent().find("a.seecomments").show();
		$(this).hide();
		
		var num = $(this).parent().parent().children(":nth-child(5)").children(":first-child").children().size();
		$(this).parent().find(".seecomments").text("Click here to add/view comments (" + num + ")");
		
		return false;
	});

	/* add comments */
	$("form.commentsadd").live("submit",function(){
		
		/* retrieve comment */
		var comment = $(this).find("textarea.commentsbox").val();
		var book_uid = parseInt($(this).find("textarea.commentsbox").attr("book_uid"));
		
		/* validate inputs--only add to page if validated */
		if (comment.length == 0 || comment.length > 255) {
			alert("Error: Comments need to be 1-255 characters in length");
			return false;
		}
		if (book_uid < 0 || book_uid > 65535) {
			alert("Error: book_uid must be between 0 and 2^16 - 1");
			return false;
		}		
		
		/* place the new comment on the page, send request to put in DB */		
		$.post("addcomment.php", 
			{book_uid: book_uid, comment: comment}, 
			function(data) {
				add_comment(comment, book_uid, data[0].uid);
			}, "json");
		
		/* clear forms after submitting */
		$(this).find("textarea.commentsbox").val("");
		
		/* make form not submit */
		return false;
	});	

}



function add_comment(comment, book_uid, comment_uid) {
	/* find the dom element to append to */
	var commentcontainer = $("div[class='commentsbody'][book_uid='" + book_uid + "']");
	
	var commentdiv = $("<div book_uid='" + book_uid + "' comment_uid='" + comment_uid + "'>").addClass("comments_one");
	commentdiv.text(comment);
	commentcontainer.append(commentdiv);
	create_X(commentdiv);
	
	var num = commentcontainer.parent().parent().children(":nth-child(5)").children(":first-child").children().size();
	commentcontainer.parent().parent().find(".seecomments").text("Click here to add/view comments (" + num + ")");
	
}



function list_books() {
	$.get("listbooks.php", function(data){
		for (var i = 0; i < data.length; i++) {
			add_book(data[i].title, data[i].author, data[i].image_url, data[i].uid);
		}
		list_comments();
	}, "json");
}



function list_comments() {
	$.get("listcomments.php", function(data){
		for (var i = 0; i < data.length; i++) {
			add_comment(data[i].comment, data[i].book_uid, data[i].uid);
		}
	}, "json");
}



function add_book(title, authors, imageurl, book_uid) {
	
	/* construct image url */
	var newimage = $("<td>").addClass("bookimage");
	if(imageurl)
		var newurl = $("<img>").attr("src",imageurl);
	newimage.append(newurl);
	
	/* construct add comments link */
	var commentslink = $("<p>").addClass("links");
	var newcomments = $("<a>").addClass("seecomments");
	var hidecomments = $("<a>").addClass("hidecomments");
	newcomments.attr("href","");
	hidecomments.attr("href","");
	newcomments.text("Click here to add/view comments (0)");
	hidecomments.text("Click here to hide comments");
	hidecomments.hide();
	commentslink.append(hidecomments);
	commentslink.append(newcomments);
	
	/* construct comments div */
	var commentscell = $("<div>").addClass("comments"); 
	var commentsbody = $("<div book_uid='" + book_uid + "'>").addClass("commentsbody");
	var commentsadd = $("<div>").addClass("commentsadd");
	var formcommentsadd = $("<form>").attr("class","commentsadd");
	var formcommentsbox = $("<textarea book_uid='" + book_uid + "'>").addClass("commentsbox");
	var formcommentssubmit = $("<input>").attr("type","submit").attr("value","Add Comment");
	formcommentsadd.append(formcommentsbox);
	formcommentsadd.append($("<br>"));
	formcommentsadd.append(formcommentssubmit);
	commentsadd.append(formcommentsadd);
	commentscell.append(commentsbody);
	commentscell.append(commentsadd);
	commentscell.hide();
	
	/* construct book information */
	var newbookinfo = $("<td book_uid='" + book_uid + "'>").addClass("bookinfo");
	create_X(newbookinfo);
	var newtitle = $("<p>").addClass("booktitle").text(title);
	var newauthors = $("<p>").addClass("bookauthors").text("by " + authors);
	newauthors.addClass(authors.toLowerCase())
	newtitle.addClass(title.toLowerCase())
	newbookinfo.append(newtitle);
	newbookinfo.append(newauthors);
	newbookinfo.append(commentslink);
	newbookinfo.append(commentscell);
	
	/* append to DOM */
	var newbook = $("<tr book_uid='" + book_uid + "'>").addClass("bookrow");
	newbook.append(newimage);
	newbook.append(newbookinfo);
	$("tbody#list_tbody").prepend(newbook);
	
}