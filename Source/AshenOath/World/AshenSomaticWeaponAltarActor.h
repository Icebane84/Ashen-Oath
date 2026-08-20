// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenSomaticWeaponAltarActor.generated.h"

/**
 * AAshenSomaticWeaponAltarActor
 * Campfire resting inspection altar where Oathbringer rests, allowing players to physically observe rune cleansing progress.
 */
UCLASS()
class ASHENOATH_API AAshenSomaticWeaponAltarActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenSomaticWeaponAltarActor();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Weapon")
	float CleanedRuneRatio = 0.0f; // 0.0 to 1.0

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Weapon")
	void UpdateWeaponCleansingProgress(int32 SynarchyExecutionsCount);
};
