var elements = $('.modal-overlay, .modal');
var oneMoreElements = $('.modal-overlay, .modal-upd');
var addForm = $('.addFormClass');
var updForm = $('.updFormClass');

$('#addBtn').click(function(){
    elements.addClass('active');
    addForm[0].reset();
});

$('.close-modal').click(function(){
    elements.removeClass('active');
    //fields.val('');
});

$('#updBtn').click(function(){
    oneMoreElements.addClass('active');
    updForm[0].reset();
});

$('.close-modal-upd').click(function(){
    oneMoreElements.removeClass('active');
});