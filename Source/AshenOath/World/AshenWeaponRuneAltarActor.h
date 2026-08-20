// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenWeaponRuneAltarActor.generated.h"

/**
 * AAshenWeaponRuneAltarActor
 * In-world ancient sharpening stone and rune altar where weapon memories are consecrated.
 */
UCLASS()
class ASHENOATH_API AAshenWeaponRuneAltarActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenWeaponRuneAltarActor();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Altar")
	bool bIsAltarConsecrated = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Altar")
	void ConsecrateWeaponAtAltar();
};
