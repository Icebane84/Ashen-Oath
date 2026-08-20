// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AI/AshenTraumaEnemyMatrixTypes.h"
#include "AshenTraumaEnemyMatrixSubsystem.generated.h"

/**
 * UAshenTraumaEnemyMatrixSubsystem
 * GameInstance Subsystem managing active adversarial arguments, monster psychological targets, and encounter tiers.
 */
UCLASS()
class ASHENOATH_API UAshenTraumaEnemyMatrixSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | TEM")
	TMap<FName, FAdversarialArgument> RegisteredAdversarialArguments;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | TEM")
	void RegisterAdversarialArgument(FName MonsterID, FName TargetHero, const FString& CoreLie, const FString& Thesis, ETEMEncounterTier Tier);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | TEM")
	bool GetAdversarialArgument(FName MonsterID, FAdversarialArgument& OutArgument) const;
};
