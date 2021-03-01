// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAIC.h"

AMyAIC::AMyAIC()
{

}

void AMyAIC::BeginPlay()
{
	GEngine->AddOnScreenDebugMessage(-1, 0, FColor::Red, "gan");
}

void AMyAIC::Tick(float DeltaSeconds)
{

}
