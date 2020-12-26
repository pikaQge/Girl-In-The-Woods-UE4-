// Fill out your copyright notice in the Description page of Project Settings.


#include "Machine.h"

// Sets default values
AMachine::AMachine()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}


void AMachine::InactivateMachine_Implementation()
{

}

void AMachine::ActivateMachine_Implementation()
{

}

// Called when the game starts or when spawned
void AMachine::BeginPlay()
{
	Super::BeginPlay();
	pulseOn = false;
}

// Called every frame
void AMachine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

