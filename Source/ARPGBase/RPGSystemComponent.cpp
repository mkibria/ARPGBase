// Fill out your copyright notice in the Description page of Project Settings.


#include "RPGSystemComponent.h"

// Sets default values for this component's properties
URPGSystemComponent::URPGSystemComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void URPGSystemComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void URPGSystemComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
void URPGSystemComponent::ExperienceUp(int32 EXP)
{
	if (!LevelExperienceTable.IsEmpty()) 
	{
		ExperiencePoints += EXP;
		LevelUpCheck();
	}
}
void URPGSystemComponent::LevelUpCheck()
{
	AActor* CurrentActor = this->GetOwner();
	AARPGBaseCharacter* Owner = Cast<AARPGBaseCharacter>(CurrentActor);
	if(IsValid(Owner))
	{
		while (ExperiencePoints > LevelExperienceTable[CurrentLevel])
		{
			CurrentLevel++;
			LevelUp(Owner);
		}
	}
	
}
void URPGSystemComponent::LevelUp(AARPGBaseCharacter* Owner)
{
	// This function should be written or overwritten based on whatever rules you want the character to have when leveling
	// This is a basic example of a level up function where each time the character levels up health is increased and replenished
	UAbilitySystemComponent* ASC = Owner->GetAbilitySystemComponent();
	
	float CurrentMaxHealth = ASC->GetNumericAttribute(UARPGAttributeSet::GetHealthMaxAttribute());
	ASC->SetNumericAttributeBase(UARPGAttributeSet::GetHealthMaxAttribute(), CurrentMaxHealth + 10);
	ASC->SetNumericAttributeBase(UARPGAttributeSet::GetHealthAttribute(), CurrentMaxHealth+10);
}

void URPGSystemComponent::LevelingSystemInit(TArray<int32> LevelUpInitTable)
{
	LevelExperienceTable = LevelUpInitTable;
	MaxLevel = LevelExperienceTable.Num() + 1;
}



