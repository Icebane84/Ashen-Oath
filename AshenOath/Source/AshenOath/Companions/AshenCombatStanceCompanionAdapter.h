// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenCombatStanceTypes.h"
#include "AshenCombatStanceCompanionAdapter.generated.h"

/**
 * UAshenCombatStanceCompanionAdapter
 * Coordinates companion tactics in response to Kaelen's active stance (Garrett taunts during Berserk, Serafina channels focus during Flow).
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCombatStanceCompanionAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenCombatStanceCompanionAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companions")
	FName GetCompanionSynergyRole(FName CompanionID, ECombatStance PlayerStance);
};
