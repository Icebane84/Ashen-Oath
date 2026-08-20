// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenRealityFractureAnchorActor.generated.h"

/**
 * AAshenRealityFractureAnchorActor
 * Spatial anchor stabilizing torn geometry and restoring physical environmental integrity.
 */
UCLASS()
class ASHENOATH_API AAshenRealityFractureAnchorActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenRealityFractureAnchorActor();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Reality")
	float StabilizationRadius = 1200.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Reality")
	bool bIsAnchorStabilized = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Reality")
	bool ConsecrateAnchor(AActor* InstigatingPlayer);
};
