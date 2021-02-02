package main

import "golang.org/x/tour/reader"

type MyReader struct{}

func (m MyReader) Read(p []byte) (n int, err error) {
	for i := range p {
		p[i] = 'A'
	}
	return len(p), nil
}

// TODO: Add a Read([]byte) (int, error) method to MyReader.

func main() {
	reader.Validate(MyReader{})
}
