// Copyright Phoenix Protocol. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "AshenCharacterInterface.generated.h"

class UAshenOath_HealthComponent;
class UAshenOath_EquipmentComponent;
class UAshenOath_InventoryComponent;
class UAshenOath_StatsComponent;
class UAshenOath_SanityComponent;
class UAshenOath_StaminaComponent;
class UAshenOath_ManaComponent;
class UAshenOath_PoiseComponent;

UINTERFACE(MinimalAPI, BlueprintType)
class UAshenCharacterInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * IAshenCharacterInterface
 * Common interface implemented by character actors to expose components without direct class casting.
 */
class ASHENOATH_API IAshenCharacterInterface
{
	GENERATED_BODY()

public:
	/** Get the health component associated with the character */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "AshenOath|CharacterInterface")
	UAshenOath_HealthComponent* GetHealthComponent() const;

	/** Get the equipment component associated with the character */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "AshenOath|CharacterInterface")
	UAshenOath_EquipmentComponent* GetEquipmentComponent() const;

	/** Get the inventory component associated with the character */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "AshenOath|CharacterInterface")
	UAshenOath_InventoryComponent* GetInventoryComponent() const;

	/** Get the stats component associated with the character */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "AshenOath|CharacterInterface")
	UAshenOath_StatsComponent* GetStatsComponent() const;

	/** Get the sanity component associated with the character */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "AshenOath|CharacterInterface")
	UAshenOath_SanityComponent* GetSanityComponent() const;

	/** Get the stamina component associated with the character */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "AshenOath|CharacterInterface")
	UAshenOath_StaminaComponent* GetStaminaComponent() const;

	/** Get the mana component associated with the character */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "AshenOath|CharacterInterface")
	UAshenOath_ManaComponent* GetManaComponent() const;

	/** Get the poise component associated with the character */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "AshenOath|CharacterInterface")
	UAshenOath_PoiseComponent* GetPoiseComponent() const;
};
