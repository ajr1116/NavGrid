// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "NavTileComponent.h"
#include "NavLadderComponent.generated.h"

UCLASS(meta = (BlueprintSpawnableComponent))
class NAVGRID_API UNavLadderComponent : public UNavTileComponent
{
	GENERATED_BODY()
public:
	UNavLadderComponent(const FObjectInitializer &ObjectInitializer);
	virtual void BeginPlay() override;

	TArray<FVector> *GetContactPoints() override;

	virtual FVector GetPawnLocation() const override;
	virtual void GetUnobstructedNeighbours(const UCapsuleComponent &CollisionCapsule, TArray<UNavTileComponent *> &OutNeighbours) override;
	virtual bool Obstructed(const FVector &FromPos, const UCapsuleComponent &CollisionCapsule) const override;
	virtual bool Traversable(float MaxWalkAngle, const TArray<EGridMovementMode> &AvailableMovementModes) const override;
	virtual bool LegalPositionAtEndOfTurn(float MaxWalkAngle, const TArray<EGridMovementMode> &AvailableMovementModes) const override;
	virtual void AddSplinePoints(const FVector &FromPos, USplineComponent &OutSpline, bool LastTile) const override;

	/* Helpers for determining walkable paths through this tile */
	UPROPERTY(BlueprintReadOnly, EditAnyWhere, Category = "Components") USceneComponent *BottomPathPoint;
	UPROPERTY(BlueprintReadOnly, EditAnyWhere, Category = "Components") USceneComponent *TopPathPoint;
	UPROPERTY(BlueprintReadWrite, Category = "Components") UArrowComponent *ArrowComponent;

	virtual FVector GetSplineMeshUpVector() override;
};