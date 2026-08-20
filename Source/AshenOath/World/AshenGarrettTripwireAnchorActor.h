// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenGarrettTripwireAnchorActor.generated.h"

/**
 * AAshenGarrettTripwireAnchorActor
 * In-world physical anchor actor spanning laser/wire tension lines.
 */
UCLASS()
class ASHENOATH_API AAshenGarrettTripwireAnchorActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenGarrettTripwireAnchorActor();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | World")
	bool bIsAnchored = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | World")
	void ArmTripwireAnchor();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | World")
	bool DeployTripwireAnchors(FVector StartPos, FVector EndPos);
};
