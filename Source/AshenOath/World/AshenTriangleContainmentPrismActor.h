// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenTriangleContainmentPrismActor.generated.h"

/**
 * AAshenTriangleContainmentPrismActor
 * In-world hard-light triangular containment boundary actor for Ashen Triangle: Null-Zone Collapse.
 */
UCLASS()
class ASHENOATH_API AAshenTriangleContainmentPrismActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenTriangleContainmentPrismActor();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Finisher Geometry")
	float PrismRadius = 600.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Finisher Geometry")
	bool bIsPrismCollapsed = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Finisher Geometry")
	void ImplodeContainmentPrism();
};
