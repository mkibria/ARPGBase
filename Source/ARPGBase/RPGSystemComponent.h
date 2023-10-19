// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ARPGBaseCharacter.h"
#include "RPGSystemComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ARPGBASE_API URPGSystemComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URPGSystemComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION(BlueprintCallable, Category = "Leveling System")
	virtual void LevelUpCheck();
	UFUNCTION(BlueprintCallable, Category = "Leveling System")
	virtual void LevelUp(AARPGBaseCharacter* Owner);
	UFUNCTION(BlueprintCallable, Category = "Leveling System")
	void ExperienceUp(int32 EXP);
	UFUNCTION(BlueprintCallable, Category = "Leveling System")
	void LevelingSystemInit(TArray<int32> LevelUpInitTable);
	UFUNCTION(BlueprintCallable, Category = "Skill System")
	bool SkillUnlockCost(int32 SkillPointsUsed);
	UFUNCTION(BlueprintCallable, Category = "Skill System")
	int32 GetSkillPoints();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Leveling System")
	int32 ExperiencePoints = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Leveling System")
	int32 CurrentLevel = 1;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Leveling System")
	TArray<int32> LevelExperienceTable;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Leveling System")
	int32 MaxLevel = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Skill System")
	int32 SkillPoints = 0;

};
