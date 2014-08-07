var RE_PATH = new RegExp( '[/](:([^/]+))', 'g' );
var SP4 = '    ';
var SP8 = SP4 + SP4;
var TESTDATA;

function stringify( arg ){
    return JSON.stringify( arg, null, 4 )
               .replace( /\[/g, '{' )
               .replace( /\]/g, '}' )
               .replace( /\n/g, '\n' + SP4 + SP4 );
}

function path2testdata( path )
{
    var str;
    var items = [];
    var match;
    
    while( ( match = RE_PATH.exec( path ) ) ){
        //console.log( match );
        items.push([ match[1], match[2] ]);
    }
    
    str = '{ \n' + SP4 +
        '.path = "' + path + '", \n' + SP4 +
        '.key = "' + path.replace( /:/g, '' ) + '", \n' + SP4 +
        '{ \n' + SP8 +
        '.nitems = ' + items.length + ',\n';
    if( items.length ){
        str += SP8 +
            '.items = (usher_glob_item_t[])' +
            stringify( items ) +
            '\n' + SP4;
    }
    else {
        str += SP4;
    }
    
    str += '}\n}';
    
    return SP4 + str.replace( /\n/g, '\n' + SP4 );
}

function format( datafile )
{
    var testdata = require( datafile ),
        data = testdata.data.map( path2testdata );
    
    return (
        'static const testdata_t ' + testdata.name + '[' +
        data.length + '] = {\n' +
        data.join(',\n') +
        '\n};'
    );
}

console.log(
    ['./github','./static'].map( format ).join('\n')
);

