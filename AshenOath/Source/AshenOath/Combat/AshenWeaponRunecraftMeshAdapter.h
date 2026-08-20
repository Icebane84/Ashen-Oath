// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenWeaponRunecraftMeshAdapter.generated.h"

/**
 * UAshenWeaponRunecraftMeshAdapter
 * Dynamically clears soot layers and enables Eldorian gold rune emissive glow along Oathbringer's fuller based on Synarchy finisher resolutions.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenWeaponRunecraftMeshAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenWeaponRunecraftMeshAdapter();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Weapon")
	float SootLayerOpacity = 1.0f; // 1.0 (Full Soot) down to 0.0 (Clean Gold Runes)

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Weapon")
	float GoldRuneEmissiveIntensity = 0.0f; // 0.0 to 2.5

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Weapon")
	void UpdateRunecraftState(int32 TotalSynarchyKills);
};
