// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenWhiteFlameResolutionHandler.generated.h"

/**
 * UAshenWhiteFlameResolutionHandler
 * Handler executing Path B: Restraint (The White Flame Resolution) — triggering micro-deflection, enemy momentum shatter AI, and State.Willpower.Unbroken buff.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenWhiteFlameResolutionHandler : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenWhiteFlameResolutionHandler();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | White Flame")
	bool bWillpowerUnbrokenBuffActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | White Flame")
	bool ExecuteWhiteFlameRestraint();
};
