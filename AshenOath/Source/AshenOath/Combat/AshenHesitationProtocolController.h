// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenHesitationProtocolController.generated.h"

/**
 * UAshenHesitationProtocolController
 * Controller executing Default Character Agency (The Hesitation Protocol) when player freezes during the 2.0s crisis window.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenHesitationProtocolController : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenHesitationProtocolController();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Hesitation")
	bool bDefaultInstinctExecuted = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Hesitation")
	bool ResolveDefaultCharacterInstinct();
};
