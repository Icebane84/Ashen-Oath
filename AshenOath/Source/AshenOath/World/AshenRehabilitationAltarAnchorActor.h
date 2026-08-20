// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenRehabilitationAltarAnchorActor.generated.h"

/**
 * AAshenRehabilitationAltarAnchorActor
 * Physical altar mesh anchor receiving Kaelen's Oathbringer during ritual.
 */
UCLASS()
class ASHENOATH_API AAshenRehabilitationAltarAnchorActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenRehabilitationAltarAnchorActor();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | World")
	void DockOathbringerBlade();
};
