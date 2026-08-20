// Copyright Phoenix Protocol. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenOath_StatsComponent.generated.h"

class UAshenOath_HealthComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLevelUpSignature, int32, NewLevel);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnXpGainedSignature, int32, AmountGained, int32, TotalXp);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenOath_StatsComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenOath_StatsComponent();

protected:
	virtual void BeginPlay() override;

public:
	/** Getters & Setters for Base Attributes */
	UFUNCTION(BlueprintPure, Category = "AshenOath|Stats")
	int32 GetVitality() const { return Vitality; }

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Stats")
	void SetVitality(int32 NewVitality);

	UFUNCTION(BlueprintPure, Category = "AshenOath|Stats")
	int32 GetStrength() const { return Strength; }

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Stats")
	void SetStrength(int32 NewStrength);

	UFUNCTION(BlueprintPure, Category = "AshenOath|Stats")
	int32 GetDexterity() const { return Dexterity; }

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Stats")
	void SetDexterity(int32 NewDexterity);

	/** Getters for Progression */
	UFUNCTION(BlueprintPure, Category = "AshenOath|Stats")
	int32 GetLevel() const { return Level; }

	UFUNCTION(BlueprintPure, Category = "AshenOath|Stats")
	int32 GetExperience() const { return Experience; }

	UFUNCTION(BlueprintPure, Category = "AshenOath|Stats")
	int32 GetXpRequirement() const;

	/** XP Progression Hooks */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Stats")
	void AddXp(int32 Amount);

	/** Load stats state dynamically from save game */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Stats")
	void LoadStatsState(int32 InLevel, int32 InXP);

	/** Formulas */
	UFUNCTION(BlueprintPure, Category = "AshenOath|Stats")
	float GetMaxHealthFormula() const;

	UFUNCTION(BlueprintPure, Category = "AshenOath|Stats")
	float GetAttackPowerFormula() const;

public:
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Stats|Events")
	FOnLevelUpSignature OnLevelUp;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Stats|Events")
	FOnXpGainedSignature OnXpGained;

private:
	void LevelUp();
	void SyncMaxHealth();

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", meta = (AllowPrivateAccess = "true"))
	int32 Vitality;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", meta = (AllowPrivateAccess = "true"))
	int32 Strength;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes", meta = (AllowPrivateAccess = "true"))
	int32 Dexterity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Progression", meta = (AllowPrivateAccess = "true"))
	int32 Level;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Progression", meta = (AllowPrivateAccess = "true"))
	int32 Experience;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Progression", meta = (AllowPrivateAccess = "true"))
	int32 XpRequirementBase;

	UPROPERTY(Transient)
	UAshenOath_HealthComponent* HealthComponent;
};
